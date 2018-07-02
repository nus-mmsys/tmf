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

#include "idct.h"

using namespace df;
using namespace std;

ActorRegister<Idct> Idct::reg("Idct");

Idct::Idct(const string& name) : Actor(name) {
  input = createInputPort<df::Mat>("input");
  output = createOutputPort<df::Mat>("output");
}

void Idct::init() {

}

void Idct::run() {

  auto in = consume(input);	
  auto out = produce(output);
  in->data->convertTo(*out->data, CV_32F);
  cv::idct(*out->data, *out->data);
  log("sending frame "+to_string(stepno));
  release(input);
  release(output);

}

Idct::~Idct() {
  destroyPort(input);
  destroyPort(output);
}
