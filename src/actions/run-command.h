/**
 * Copyright 2011 - 2020 José Expósito <jose.exposito89@gmail.com>
 *
 * This file is part of Touchégg.
 *
 * Touchégg is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 3 of the License,  or (at your option)  any later
 * version.
 *
 * Touchégg is distributed in the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Touchégg. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ACTIONS_RUN_COMMAND_H_
#define ACTIONS_RUN_COMMAND_H_

#include <string>

#include "actions/repeated-action.h"

/**
 * Action to emulate a shortcut.
 */
class RunCommand : public RepeatedAction {
 public:
  using RepeatedAction::RepeatedAction;
  bool runOnSystemWindows() override { return true; }
  virtual void executePrelude() override;
  virtual void executeAction(const Gesture &gesture) override;
  virtual void executeReverse(const Gesture &gesture) override;

 private:
  std::string command;
  std::string decreaseCommand;

  static bool runCommand(const std::string &command);
};

#endif  // ACTIONS_RUN_COMMAND_H_
