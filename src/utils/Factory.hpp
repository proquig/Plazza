//
// Created by pogam-_g on 4/18/16.
//

#ifndef CPP_PLAZZA_FACTORY_HPP
#define CPP_PLAZZA_FACTORY_HPP

#include <map>

template<class Object, class Key=std::string>
class Factory
{
  static std::map<Key, Object *> _map;
 public:
  ~Factory();

  static void registerType(Key key, Object *obj);

  Object *create(const Key &key);
};

template<class Object, class Key> std::map<Key, Object *> Factory<Object, Key>::_map = std::map<Key, Object *>();

Factory::~Factory()
{
}

template<class Object, class Key>
void Factory<Object, Key>::registerType(Key key, Object *obj)
{
  if (_map.find(key) == _map.end())
    _map[key] = obj;
}

template<class Object, class Key>
Object *Factory<Object, Key>::create(const Key &key)
{
  Object *tmp = nullptr;
  typename std::map<Key, Object *>::iterator it = _map.find(key);

  if (it != _map.end())
    {
      tmp = ((*it).second)->clone();
    }

  return tmp;
}


#endif //CPP_PLAZZA_FACTORY_HPP
