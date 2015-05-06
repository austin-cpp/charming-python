//
// task_list.hpp
// ~~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SAMPLE_TASK_LIST_HPP
#define SAMPLE_TASK_LIST_HPP

#include <cstdint>
#include <list> // std::list
#include <memory> // std::shared_ptr
#include <sample/task.hpp>

namespace sample {

class task_list_observer;

/// @brief Collection of `task`.
class task_list
{
public:

  typedef std::shared_ptr<task> element_type;
  typedef std::list<element_type> tasks;
  typedef std::list<task_list_observer*> observers;

private:

  task_list();
  task_list(const task_list&) = delete;
  task_list(task_list&&) = delete;
  task_list& operator=(const task_list&) = delete;
  task_list& operator=(const task_list&&) = delete;

public:

  static task_list* create();
  ~task_list();

public:

  void add(element_type task);

  void remove(element_type task);

  tasks all() const;

  void attach(task_list_observer*);

  void detach(task_list_observer*);

private:

  tasks tasks_;
  observers observers_;

};

task_list::tasks active(const task_list& list);

task_list::tasks completed(const task_list& list);

} // namespace sample

#endif // SAMPLE_TASK_LIST_HPP
