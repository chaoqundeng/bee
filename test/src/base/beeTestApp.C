//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "beeTestApp.h"
#include "beeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<beeTestApp>()
{
  InputParameters params = validParams<beeApp>();
  return params;
}

beeTestApp::beeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  beeApp::registerObjectDepends(_factory);
  beeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  beeApp::associateSyntaxDepends(_syntax, _action_factory);
  beeApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  beeApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    beeTestApp::registerObjects(_factory);
    beeTestApp::associateSyntax(_syntax, _action_factory);
    beeTestApp::registerExecFlags(_factory);
  }
}

beeTestApp::~beeTestApp() {}

void
beeTestApp::registerApps()
{
  registerApp(beeApp);
  registerApp(beeTestApp);
}

void
beeTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
beeTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
beeTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
beeTestApp__registerApps()
{
  beeTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
beeTestApp__registerObjects(Factory & factory)
{
  beeTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
beeTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  beeTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
beeTestApp__registerExecFlags(Factory & factory)
{
  beeTestApp::registerExecFlags(factory);
}
