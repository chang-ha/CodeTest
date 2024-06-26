#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
class MyNode
{
private:
    friend class MyBinaryTree;

    MyNode(int _Data)
        : Data(_Data)
    {

    }

    ~MyNode()
    {
        if (nullptr != LeftChild)
        {
            delete LeftChild;
        }

        if (nullptr != RightChild)
        {
            delete RightChild;
        }
    }

    int Data = -1;
    MyNode* ParentNode = nullptr;
    MyNode* LeftChild = nullptr;
    MyNode* RightChild = nullptr;
};

class MyBinaryTree
{
public:
    MyBinaryTree()
    {
        RootNode = new MyNode(1);
        MapSize += 1;
    }

    ~MyBinaryTree()
    {
        delete RootNode;
    }

    void SwapChild(MyNode* _ParentNode)
    {
        MyNode* TempNode = _ParentNode->LeftChild;
        _ParentNode->LeftChild = _ParentNode->RightChild;
        _ParentNode->RightChild = TempNode;
    }

    void SwapChild(MyNode* _ParentNode, int _Depth)
    {
        if (nullptr == _ParentNode)
        {
            return;
        }

        if (0 == GetDepth(_ParentNode) % _Depth)
        {
            SwapChild(_ParentNode);
        }

        SwapChild(_ParentNode->LeftChild, _Depth);
        SwapChild(_ParentNode->RightChild, _Depth);
    }

    void Insert(const  int _Data)
    {
        MyNode* InsertNode = new MyNode(_Data);

        queue<MyNode*> SearchQueue;
        SearchQueue.push(RootNode);

        MyNode* CurNode = nullptr;
        while (!SearchQueue.empty())
        {
            CurNode = SearchQueue.front();
            SearchQueue.pop();

            if (-1 == CurNode->Data)
            {
                continue;
            }

            if (nullptr == CurNode->LeftChild)
            {
                CurNode->LeftChild = InsertNode;
                InsertNode->ParentNode = CurNode;
                MapSize += 1;
                break;
            }
            else
            {
                SearchQueue.push(CurNode->LeftChild);
            }

            if (nullptr == CurNode->RightChild)
            {
                CurNode->RightChild = InsertNode;
                InsertNode->ParentNode = CurNode;
                MapSize += 1;
                break;
            }
            else
            {
                SearchQueue.push(CurNode->RightChild);
            }
        }
    }

    int GetDepth(MyNode* _Node)
    {
        MyNode* _CurNode = _Node;
        int Depth = 1;
        while (nullptr != _CurNode->ParentNode)
        {
            _CurNode = _CurNode->ParentNode;
            Depth += 1;
        }

        return Depth;
    }

    MyNode* GetRootNode()
    {
        return RootNode;
    }

    vector<int> GetInorderTraversal()
    {
        vector<int> ResultVector;
        ResultVector.reserve(MapSize);
        InorderTraversal(RootNode, ResultVector);
        return ResultVector;
    }

protected:
    MyNode* RootNode = nullptr;
    int MapSize = 0;

private:
    void InorderTraversal(MyNode* _Node, vector<int>& _Vector)
    {
        if (nullptr != _Node->LeftChild)
        {
            InorderTraversal(_Node->LeftChild, _Vector);
        }

        if (-1 != _Node->Data)
        {
            _Vector.push_back(_Node->Data);
        }

        if (nullptr != _Node->RightChild)
        {
            InorderTraversal(_Node->RightChild, _Vector);
        }
    }
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    MyBinaryTree BinaryTree;

    for (const vector<int>& _CurVector : indexes)
    {
        for (const int _CurData : _CurVector)
        {
            BinaryTree.Insert(_CurData);
        }
    }

    std::vector<vector<int>> Result;

    for (const int _CurQuery : queries)
    {
        BinaryTree.SwapChild(BinaryTree.GetRootNode(), _CurQuery);
        Result.push_back(BinaryTree.GetInorderTraversal());
    }

    return Result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
