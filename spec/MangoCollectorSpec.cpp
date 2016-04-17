
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/MangoCollector.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MangoCollectorSpec
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


		struct node *newNode(int key)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		struct node * constructBinaryTree_spec(int *arr, int len){
			struct node *root = NULL;
			struct node *nodes[100];
			for (int i = 0; i < len; i++){
				nodes[i] = newNode(arr[i]);
			}
			int mid = (len / 2);
			for (int i = 0; i < mid; i++){
				struct node *curnode = nodes[i];
				struct node *leftnode = nodes[(i * 2) + 1];
				struct node *rightnode = nodes[(i * 2) + 2];
				if (curnode->data != -999){
					if (leftnode->data != -999){
						curnode->left = leftnode;
					}
					if (rightnode->data != -999){
						curnode->right = rightnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}

		int compare_arrays_mc_spec(int *arr1, int *arr2, int len){
			int i = 0;
			while (i < len){
				if (arr1[i] != arr2[i]){
					return 0;
				}
				i++;
			}
			return 1;
		}
		void testMangoCollector(int advance,int *arr, int k,int ways_exp,int len,int *shortestpath_exp, int shortestpath_len_exp){
			struct node *root = constructBinaryTree_spec(arr, len);
			int finalarray[1000];
			int fl = 0;
			int ways = 0;
			ways = mangocity_count_ways(root, k, finalarray, &fl);
			Assert::AreEqual(ways_exp, ways, L"Failed for Ways in MangoCollector", 1, 2);

			//Advance check checks ,shortestpath array and Len too ,Make it 0 ,if you want to Run only
			//for ways
			if (advance){
				Assert::AreEqual(fl, shortestpath_len_exp, L"Failed for ShortestPath Len in MangoCollector", 1, 2);
				if (fl == shortestpath_len_exp){
					int check = compare_arrays_mc_spec(finalarray, shortestpath_exp, shortestpath_len_exp);
					Assert::AreEqual(1, check, L"Failed for ShortestPath in MangoCollector", 1, 2);
				}
			}

		}
#pragma region Additional test attributes
#pragma endregion 
		[TestMethod, Timeout(1000)]
		void Sample1_MangoCollector()
		{
			struct node *head = NULL;
			int fl = 0;
			int res = mangocity_count_ways(head,0,NULL,&fl);
			Assert::AreEqual(-1, res, L"Failed sample 0 for NULL case in LL", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_MangoCollector()
		{
		    //-999 Elements will not be created
			int arr[] = { 5,4,3,-3,-1,-999,-999 };
			int k = 8;
			int ways_exp = 2;
			int shortestpath[] = { 5,3 };
			int shortestpath_len = 2;
			int len = sizeof(arr) / sizeof(arr[0]);
			testMangoCollector(0, arr, k, ways_exp, len, shortestpath, shortestpath_len);
		};
		[TestMethod, Timeout(1000)]
		void Sample3_MangoCollector()
		{
			//-999 Elements will not be created
			int arr[] = { 10, 5, -2, 5, 1, 9, 9, -999, -999, 10, 1, -999, -999, 3, -1, -999, -999, -999, -999, -999, -999,
				-999, -999, -999, -999, -999, -999, -999, -999, -999, 1 };
			int k = 17;
			int ways_exp = 3;
			int shortestpath[] = {10,-2,9};
			int shortestpath_len = 3;
			int len = sizeof(arr) / sizeof(arr[0]);
			testMangoCollector(1,arr, k,ways_exp, len, shortestpath, shortestpath_len);
		};

	};
}

