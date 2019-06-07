/*
 *   TMF
 *   Copyright (C) TMF Team
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

#include "matjoin.h"

using namespace df;
using namespace std;

ActorRegister<MatJoin> MatJoin::reg("MatJoin");

MatJoin::MatJoin(const string& name) : Actor(name) {
  input = createInputPortVector<df::Mat>("input");
  output = createOutputPort<df::Mat>("output");
}

void MatJoin::init() {

  if (propEmpty("level"))
	  level = 1;
  else
	  level = getPropInt("level");

  tilew = 0;
  tileh = 0;

  input->setArity(level);

  if (output->getRate()!=level) {
	log("Join output rate is not equal its input edges.");
	exit(0);
  }

}

void MatJoin::reinit() {

  auto newlevel = getPropInt("level");

  if (newlevel > level) {
  	input->addArity(newlevel - level);
  }

  level = newlevel;
  tilew = 0;
  tileh = 0;

}

void MatJoin::run() {

  auto in = consume(input);	
  auto out = produceMR(output);

  for (int j=0; j<out.size(); j++) {
	  out[j]->set(*in[j]->get());
  }

  log("sending "+to_string(stepno));
  
  releaseMR(output);
  release(input);

}

MatJoin::~MatJoin() {
  destroyPort(input);
  destroyPort(output);
}
