#include "beeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<beeApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

beeApp::beeApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  beeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  beeApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  beeApp::registerExecFlags(_factory);
}

beeApp::~beeApp() {}

void
beeApp::registerApps()
{
  registerApp(beeApp);
}

void
beeApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"beeApp"});
}

void
beeApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"beeApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
beeApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
beeApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
beeApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
beeApp__registerApps()
{
  beeApp::registerApps();
}

extern "C" void
beeApp__registerObjects(Factory & factory)
{
  beeApp::registerObjects(factory);
}

extern "C" void
beeApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  beeApp::associateSyntax(syntax, action_factory);
}

extern "C" void
beeApp__registerExecFlags(Factory & factory)
{
  beeApp::registerExecFlags(factory);
}
