#include "lt.h"

#include <algorithm>

namespace LT455_AssignCookie
{
    // Greedy 
    #if 0
    static int findMaximalChildEatCookie(vector<int>& children, vector<int>& cookies)
    {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int childNum = 0; // satified
        int i = 0, j = 0;
        while(i < children.size() && j < cookies.size())
        {
            if(children[i] <= cookies[j])
            {
                childNum++;
                i++;
            }
            j++;
        }

        return childNum;
    }
    #endif

    static int findMaximalChildEatCookie(vector<int>& children, vector<int>& cookies)
    {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int child = 0, cookie = 0;
        while(child < children.size() && cookie < cookies.size())
        {
            if(children[child] <= cookies[cookie++])
                child++;
        }

        return child;
    }

    static void execute()
    {
        ENTER();

        {
            vector<int> children = {2,1}, cookies = {3,1,2};
            cout << findMaximalChildEatCookie(children, cookies) << endl;
        }

        {
            vector<int> children = {2,1,5}, cookies = {3,1,2,5};
            cout << findMaximalChildEatCookie(children, cookies) << endl;
        }

        {
            cout << "Please input test case number, childrenNum1&children1, cookie1Num&cookie1, childrenNum2&children2, cookie2Num&cookie2, ..." << endl;
            int caseNum;
            cin >> caseNum;
            for(int i = 0; i < caseNum; ++i)
            {
                int childrenNum, cookieNum;
                cin >> childrenNum;
                cin >> cookieNum;
                cout << "childrenNum: " << childrenNum << " cookieNum: " << cookieNum << endl;
                vector<int> children(childrenNum), cookies(cookieNum);
                for(int j = 0; j < childrenNum; ++j)
                    cin >> children[j];
                
                for(int j = 0; j < cookieNum; ++j)
                    cin >> cookies[j];
                    
                cout << findMaximalChildEatCookie(children, cookies) << endl;
            }
        }
    }

}

namespace LT135_Candy
{
    static int computeMaxCandy(vector<int>& ratings)
    {
        return 0;
    }

    static void execute()
    {
        ENTER();
        
        {
            vector<int> ratings = {1, 0, 2};
            cout << computeMaxCandy(ratings) << endl; //  [2, 1, 2] 5
        }
        {
            vector<int> ratings = {1, 0, 1, 0};
            cout << computeMaxCandy(ratings) << endl; // [2, 1, 2, 1] 6
        }
        {
            vector<int> ratings = {1, 2, 3, 4};
            cout << computeMaxCandy(ratings) << endl; // [1, 2, 3, 4] 10
        }
    }
}

void ltMain()
{
   // LT455_AssignCookie::execute();
    LT135_Candy::execute();
}