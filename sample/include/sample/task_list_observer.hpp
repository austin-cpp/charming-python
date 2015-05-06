//
// task_list_observer.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SAMPLE_TASK_LIST_OBSERVER_HPP
#define SAMPLE_TASK_LIST_OBSERVER_HPP

#include <cstdint>
#include <list> // std::list
#include <memory> // std::shraed_ptr

namespace sample {

/// @brief Observer that can attach to a `task_list`.
class task_list_observer
{
public:

  virtual ~task_list_observer();

public:

  /// @brief Invoked when a task has been added to the list.
  virtual void on_add() = 0;

  /// @brief Invoked when a task has been removed from the list.
  virtual void on_remove() = 0;
};

} // namespace sample

#endif // SAMPLE_TASK_LIST_OBSERVER_HPP
