#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/CommonRoute.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class CommonRouteSpec
	{
	private:
		TestContext^ testContextInstance;
	public:
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
#pragma endregion 
		void testCommonRoute(char *s1, char *s2, int a, int b){
			int i = 0;
			while (s1[i] != '\0'){
				if (s1[i] != s2[i]){
					Assert::AreEqual(1, 2, L"Failed Route", 1, 2);
					return;
				}
				i++;
			}
			Assert::AreEqual(b,a, L"Failed Cost for CommonRoute", 1, 2);
		}
		[TestMethod, Timeout(1000)]
		void Sample1_CommonRoute()
		{
			int cost = 0;
			char *res = find_common_route(NULL,NULL,&cost);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed sample 1 for CommonRoute", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_CommonRoute()
		{
			int cost = -1; 
			char hacklist[100] = "CADBZAYZY";
			char codelist[100] = "BZAYACAFRDBZ";
			char ans[100] = "BZAY";
			int cost_ans = 54;
			char *res=NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null", 1, 2);
			}
			testCommonRoute(res,ans, cost, cost_ans);
			
		};
		
	};
}
