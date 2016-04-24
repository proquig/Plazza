//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include <sstream>
#include <wait.h>
#include "Process.hpp"
#include "../utils/Factory.hpp"
#include "../utils/Parser.hpp"
#include "../utils/Decrypt.hpp"
#include "ThreadPool.hpp"

Plazza::Process::Process(size_t maxThreads, int processId)
	: _lastAction(std::time(nullptr)), _pool(nullptr), _ordersRunning(0), _maxThreads(maxThreads),
	  _terminated(false)
{
  this->_fifos.push_back(new Fifo("plazza-" + std::to_string(processId) + "main-process"));
  this->_fifos.push_back(new Fifo("plazza-" + std::to_string(processId) + "process-main"));

  this->_fork = new Fork();
  if (this->_fork->isChild())
    {
      this->_writer = this->_fifos[0];
      this->_reader = this->_fifos[1];
      this->_pool = new ThreadPool(maxThreads, &parseFile);
      this->_pool->addObserver(this);
      new std::thread(&Process::timeTracker, this);
      new std::thread(&Process::messageReader, this);
    }
  else
    {
      this->_reader = this->_fifos[0];
      this->_writer = this->_fifos[1];
      new std::thread(&Process::waitEnd, this, this->_fork->get_pid());
    }
}

Plazza::Process::~Process()
{
  this->_reader->write("end");
  this->_writer->write("end");
  delete this->_fifos[0];
  delete this->_fifos[1];
  if (this->_pool != nullptr)
    delete this->_pool;
  delete this->_fork;
}

bool Plazza::Process::askCanAcceptOrder()
{
  if (this->_terminated)
    return false;
  this->_writer->write("canAcceptOrder");
  usleep(100);
  std::string response = this->_reader->read();
  return response == "true";
}

void Plazza::Process::sendOrder(const IOrder &order)
{
  std::stringstream stream("");
  stream << order;
  this->_writer->write(stream.str());
}

void Plazza::Process::stop()
{
  this->_pool->stop();
  delete (this);
}

void Plazza::Process::update()
{
  this->_ordersRunning--;
  if (this->_ordersRunning == 0)
    this->_lastAction = std::time(nullptr);
}

void Plazza::Process::timeTracker()
{
  for (;;)
    {
      if (this->_ordersRunning == 0)
	{
	  if (std::time(nullptr) - this->_lastAction >= 4)
	    {
	      this->stop();
	      return;
	    }
	}
      usleep(100);
    }
}

void Plazza::Process::messageReader()
{
  for (;;)
    {
      std::string message = this->_reader->read();
      if (message.length())
	{
	  if (message == "end")
	    break;
	  parseMessage(message);
	}
    }
}

void Plazza::Process::waitEnd(pid_t pid)
{
  waitpid(pid, NULL, 0);
  this->_terminated = true;
}

void Plazza::Process::parseMessage(const std::string message)
{
  std::stringstream stream(message);
  std::string command;
  std::string file;
  IOrder *order;

  std::getline(stream, command, ' ');
  if (command == "canAcceptOrder")
    this->_writer->write(this->_ordersRunning < (this->_maxThreads * 2) ? "true" : "false");
  else
    {
      std::getline(stream, file, ' ');
      order = deserialize(command, file);
      this->_ordersRunning++;
      this->_pool->enqueue(*order);
    }
}

Plazza::IOrder *Plazza::Process::deserialize(const std::string &type, const std::string &file)
{
  Factory<IOrder> factory;
  IOrder *order;

  order = factory.create(type);
  order->setFile(file);
  return order;
}

void Plazza::Process::parseFile(const IOrder &order)
{
  try
    {
      Decrypt decrypt(order);
      std::vector<std::string> strings;

      strings = decrypt.decrypt();
      for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	std::cout << *it << std::endl;
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
}
