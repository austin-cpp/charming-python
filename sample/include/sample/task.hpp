//
// task.hpp
// ~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SAMPLE_TASK_HPP
#define SAMPLE_TASK_HPP

#include <string>

// The sample below is designed to demonstrate common use cases that one may
// find present in existing libraries that need to be integrated with Python.
// For example, collections, factor functions, free functions, shared and
// exclusive ownership, etc.

namespace sample {

/// @brief Basic task object.
class task
{
public:
  task(std::string title, bool completed);

  void title(std::string);
  std::string title() const;

  void completed(bool);
  bool completed() const;

private:
  /// @brief Task title.
  std::string title_;

  /// @brief Indicate if task has been completed.
  bool completed_;
};

} // namespace sample

#endif // SAMPLE_TASK_HPP

