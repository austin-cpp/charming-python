//
// task_list.cpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm> // std::copy_if. std::for_each
#include <iostream> // std::cout, std::endl
#include <iterator> // std::back_inserter
#include <sample/task_list.hpp>
#include <sample/task_list_observer.hpp>

namespace sample {

task_list* task_list::
create()
{
  return new task_list();
}

task_list::
task_list()
{
  std::cout << "task_list() @" << this << std::endl;
}

task_list::
~task_list()
{
  std::cout << "~task_list() @" << this << std::endl;
}

void task_list::
add(task_list::element_type task)
{
  tasks_.push_back(task);

  // Notify observers.
  for (auto& observer: observers_)
  {
    observer->on_add();
  }
}

void task_list::
remove(task_list::element_type task)
{
  tasks_.remove(task);

  // Notify observers.
  for (auto& observer: observers_)
  {
    observer->on_remove();
  }
}

task_list::tasks task_list::
all() const
{
  return tasks_;
}

void task_list::
attach(task_list_observer* observer)
{
  observers_.push_back(observer);
}

void task_list::
detach(task_list_observer* observer)
{
  observers_.remove(observer);
}

namespace detail {

template <typename Predicate>
task_list::tasks filter_task_list(
  const task_list& list,
  Predicate predicate)
{
  auto tasks = list.all();
  task_list::tasks result;

  std::copy_if(
    tasks.begin(), tasks.end(), 
    std::back_inserter(result),
    predicate);

  return result;
}

} // namespace detail

task_list::tasks active(const task_list& list)
{
  return detail::filter_task_list(list,
    [](const task_list::element_type& ptr)
    {
      return !ptr->completed();
    });
}

task_list::tasks completed(const task_list& list)
{
  return detail::filter_task_list(list,
    [](const task_list::element_type& ptr)
    {
      return ptr->completed();
    });
}

} // namespace sample