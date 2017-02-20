#ifndef EVE_ORE_PRICES_H_
#define EVE_ORE_PRICES_H_

#include "Base/BaseDemoManager.h"

namespace EveOrePrices
{

	class EveOrePricesApp
		public base::BaseManager
	{
	public:
		EveOrePricesApp();
		virtual void createScene();
		virtual void destroyScene();

	private:
		void createApp();
		void destroyApp();
		virtual void setupResources();

		void colourWidgets(MyGUI::Widget* widget, const MyGUI::Colour& colour);

	private:
		MyGUI::Widget* _AppView;
		MyGUI::ComboBox* _ComboSkins;
	};

} // namespace EveOrePrices

#endif EVE_ORE_PRICES_H_
