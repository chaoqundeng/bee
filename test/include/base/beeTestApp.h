//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef BEETESTAPP_H
#define BEETESTAPP_H

#include "MooseApp.h"

class beeTestApp;

template <>
InputParameters validParams<beeTestApp>();

class beeTestApp : public MooseApp
{
public:
  beeTestApp(InputParameters parameters);
  virtual ~beeTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* BEETESTAPP_H */
