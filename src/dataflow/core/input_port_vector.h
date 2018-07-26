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

#ifndef DF_INPUTPORT_VECTOR_H
#define DF_INPUTPORT_VECTOR_H

#include "input_port.h"

namespace df {
  
  /*!
   * \class InputPortVector
   *
   */
  
  template <typename T>
  class InputPortVector: public InputPort<T> {
    
  private:

  public:
	  
    InputPortVector<T>(std::string name) : InputPort<T>(name) {
    }
    
    virtual ~InputPortVector() {
    }
    
  };
  
}
#endif // DF_INPUTPORT_VECTOR_H