/*!
	@file
	@author		Albert Semenov
	@date		08/2008
*/
#include "Precompiled.h"
#include "EveOrePricesApp.h"
#include "Main.h"

namespace EveOrePrices
{

	EveOrePricesApp::EveOrePricesApp() :
		_AppView(0),
		_ComboSkins(0)
	{
	}

	void EveOrePricesApp::createApp()
	{
		destroyApp();

		MyGUI::ResourceManager::getInstance().load("MyGUI_BlackBlueTheme.xml");
		MyGUI::VectorWidgetPtr windows = MyGUI::LayoutManager::getInstance().loadLayout("Themes.layout");
		MYGUI_ASSERT(windows.size() == 1, "Error load layout");
        
		_AppView = windows[0];

	}

	void EveOrePricesApp::colourWidgets(MyGUI::Widget* widget, const MyGUI::Colour& colour)
	{
		widget->setColourcolour);
		MyGUI::EnumeratorWidgetPtr enumerator = widget->getEnumerator();
		while (enumerator.next())
		{
			colourWidgets(enumerator.current(), colour);
		}
	}

	void EveOrePricesApp::destroyApp()
	{
		if (_DemoView)
		{
			MyGUI::WidgetManager::getInstance().destroyWidget(_DemoView);
			_DemoView = 0;
		}
		if (_ComboSkins)
		{
			_ComboSkins = 0;
		}
	}

	void EveOrePricesApp::setupResources()
	{
		base::BaseManager::setupResources();
		addResourceLocation(getRootMedia() + "/Demos/Demo_Themes");
		addResourceLocation(getRootMedia() + "/Common/Demos");
		addResourceLocation(getRootMedia() + "/Common/Themes");
	}

	void EveOrePricesApp::createScene()
	{
		base::BaseDemoManager::createScene();
		//MyGUI::LayoutManager::getInstance().loadLayout("Wallpaper.layout");
		
		createApp(0);
	}

	void DemoKeeper::destroyScene()
	{
		destroyApp();
	}

} // namespace EveOrePrices

MYGUI_APP(EveOrePrices::EveOrePricesApp)
