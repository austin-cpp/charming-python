//
// task.cpp
// ~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sample/task.hpp>

namespace sample {

task::
task(
  std::string title,
  bool completed)
 : title_(title),
   completed_(completed)
{}

void task::
title(std::string title)
{
  title_ = title;
}

std::string task::
title() const
{
  return title_;
}

void task::
completed(bool completed)
{
  completed_ = completed;
}

bool task::completed() const
{
  return completed_;
}

} // namespace sample