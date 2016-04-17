
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Pillars.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class PillarsSpec
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

		int compare_arrays_pillars_spec(int *arr1, int *arr2, int len){
			int i = 0;
			while (i < len){
				if (arr1[i] != arr2[i]){
					return 0;
				}
				i++;
			}
			return 1;
		}
		void testPillars_spec(int *blocks,int n,int m,int *maxpath_exp, int jc_exp,int nopath){
			//No path will be 1 if All are zeros or blocks is NULL
			int jc = 0;
			int *res = pillars_max_jumps(blocks, n, m, &jc);
			int check = 0;

			//If jumps are not null ,Res should not be null ,If null Fail
			if (res == NULL && jc_exp!=0){
				Assert::AreEqual(1, 2, L"Res should not be null Pillars", 1, 2);
			}
			else if (jc_exp == 0 && nopath==1){
				//As jumps are zero and there is no Path,Res should be Null ,Or else Call Failing Assert
				if (res != NULL){
					Assert::AreEqual(1, 2, L"Res should be null Pillars", 1, 2);
				}
			}
			else{
				Assert::AreEqual(jc, jc_exp, L"Failed Jump Count case in Pillars", 1, 2);
				if (jc == jc_exp){
					int flag = compare_arrays_pillars_spec(res, maxpath_exp, jc_exp + 1);
					Assert::AreEqual(1, flag, L"Failed Max jump path in Pillars", 1, 2);
				}
				
			}
			
		}
		[TestMethod, Timeout(1000)]
		void Sample1_Pillars()
		{
			int jc = 0;
			int n = 3, m = 5;
			int *res = pillars_max_jumps(NULL,n,m,&jc);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed sample 0 for NULL case in LL", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Pillars()
		{
			
			const int n = 3, m = 3;
			int blocks[n][m] = {
				{2,1,7},
				{3,0,4},
				{5,6,4}
			};
			const int jc_exp = 4;
			int maxpath_exp[jc_exp+1] = { 1, 2, 3, 5, 6 };
			int nopath = 0;
			testPillars_spec(&blocks[0][0],n,m,maxpath_exp, jc_exp,nopath);
		};
		[TestMethod, Timeout(1000)]
		void Sample3_Pillars()
		{
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 0, 1, 0 },
				{ 0, 0, 0, 9, 0 },
				{ 0, 0, 0, 8, 0 },
				{ 0, 1, 4, 6, 5 },
				{ 0, 0, 2, 3, 4 }, };
			const int jc_exp = 6;
			int maxpath_exp[jc_exp + 1] = { 2,3,4,5,6,8,9 };
			int nopath = 0;
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp,nopath);
		};

	};
}

