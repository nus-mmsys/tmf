/*
 *   libdataflow
 *   Copyright (C) 2018
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DF_RANDN_H_
#define DF_RANDN_H_

#include "core/df.h"
#include "types/opencv/mat.h"
#include <opencv2/core/core.hpp>

#include <iostream>
#include <string>

using namespace std;

class Randn: public df::Actor {
  
private:

  cv::Mat * frame;
  df::OutputPort<df::Mat> * output;
  int width, height, last;

  static  df::ActorRegister<Randn> reg;
public:
  
  Randn(const string& name);
  
  virtual void init();
  
  virtual void run();
  
  virtual ~Randn();
  
};

#endif /* DF_RANDN_H_ */
