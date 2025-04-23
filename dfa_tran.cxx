#include <format>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>

using namespace std;

constexpr std::string_view all_alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr std::string_view all_digit = "0123456789";
constexpr std::string_view all_alnum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

struct NFA_Node
{
    int                      index;
    unordered_map<char, int> next;
    bool                     isFinal = false;
};

struct DFA_Status
{
    set<int> indexs;
    bool     isVisited = false;

    bool operator==(const DFA_Status& other) const
    {
        return indexs == other.indexs;
    }
};

struct DFA_StatusHash
{
    size_t operator()(const DFA_Status& a) const
    {
        size_t hash = 0;
        for (const int i : a.indexs)
        {
            hash ^= hash * 31 + std::hash<int> {}(i);
        }
        return hash;
    }
};

int main()
{
    NFA_Node nodes[94];
    for (int i = 0; i < 88; ++i)
    {
        nodes[i].index = i;
    }

    // FUNC
    nodes[1].next    = {{'f', 2}};
    nodes[2].next    = {{'u', 3}};
    nodes[3].next    = {{'n', 4}};
    nodes[4].next    = {{'c', 5}};
    nodes[5].isFinal = true;

    // VAR
    nodes[6].next    = {{'v', 7}};
    nodes[7].next    = {{'a', 8}};
    nodes[8].next    = {{'r', 9}};
    nodes[9].isFinal = true;

    // IF
    nodes[10].next    = {{'i', 11}};
    nodes[11].next    = {{'f', 12}};
    nodes[12].isFinal = true;

    // GOTO
    nodes[13].next    = {{'g', 14}};
    nodes[14].next    = {{'o', 15}};
    nodes[15].next    = {{'t', 16}};
    nodes[16].next    = {{'o', 17}};
    nodes[17].isFinal = true;

    // RETURN
    nodes[18].next    = {{'r', 19}};
    nodes[19].next    = {{'e', 20}};
    nodes[20].next    = {{'t', 21}};
    nodes[21].next    = {{'u', 22}};
    nodes[22].next    = {{'r', 23}};
    nodes[23].next    = {{'n', 24}};
    nodes[24].isFinal = true;

    // INT
    nodes[25].next    = {{'i', 26}};
    nodes[26].next    = {{'n', 27}};
    nodes[27].next    = {{'t', 28}};
    nodes[28].isFinal = true;

    // BOOL
    nodes[29].next    = {{'b', 30}};
    nodes[30].next    = {{'o', 31}};
    nodes[31].next    = {{'o', 32}};
    nodes[32].next    = {{'l', 33}};
    nodes[33].isFinal = true;

    // ID
    for (char c : all_alpha)
    {
        nodes[34].next[c] = 35;
    }
    for (char c : all_alnum)
    {
        nodes[35].next[c] = 35;
    }
    nodes[35].isFinal = true;

    // INT_LITERAL
    for (char c : all_digit)
    {
        nodes[36].next[c] = 37;
    }
    for (char c : all_digit)
    {
        nodes[37].next[c] = 37;
    }
    nodes[37].isFinal = true;

    // ADD
    nodes[38].next    = {{'+', 39}};
    nodes[39].isFinal = true;

    // SUB
    nodes[40].next    = {{'-', 41}};
    nodes[41].isFinal = true;

    // MUL
    nodes[42].next    = {{'*', 43}};
    nodes[43].isFinal = true;

    // DIV
    nodes[44].next    = {{'/', 45}};
    nodes[45].isFinal = true;

    // EQ
    nodes[46].next    = {{'=', 47}};
    nodes[47].next    = {{'=', 48}};
    nodes[48].isFinal = true;

    // NEQ
    nodes[49].next    = {{'!', 50}};
    nodes[50].next    = {{'=', 51}};
    nodes[51].isFinal = true;

    // LT
    nodes[52].next    = {{'<', 53}};
    nodes[53].isFinal = true;

    // GT
    nodes[54].next    = {{'>', 55}};
    nodes[55].isFinal = true;

    // LE
    nodes[56].next    = {{'<', 57}};
    nodes[57].next    = {{'=', 58}};
    nodes[58].isFinal = true;

    // GE
    nodes[59].next    = {{'>', 60}};
    nodes[60].next    = {{'=', 61}};
    nodes[61].isFinal = true;

    // AND
    nodes[62].next    = {{'&', 63}};
    nodes[63].next    = {{'&', 64}};
    nodes[64].isFinal = true;

    // OR
    nodes[65].next    = {{'|', 66}};
    nodes[66].next    = {{'|', 67}};
    nodes[67].isFinal = true;

    // NOT
    nodes[68].next    = {{'!', 69}};
    nodes[69].isFinal = true;

    // BITWISE_AND
    nodes[70].next    = {{'&', 71}};
    nodes[71].isFinal = true;

    // BITWISE_OR
    nodes[72].next    = {{'|', 73}};
    nodes[73].isFinal = true;

    // BITWISE_NOT
    nodes[74].next    = {{'~', 75}};
    nodes[75].isFinal = true;

    // ASSIGN
    nodes[76].next    = {{'=', 77}};
    nodes[77].isFinal = true;

    // COMMA
    nodes[78].next    = {{',', 79}};
    nodes[79].isFinal = true;

    // SEMICOLON
    nodes[80].next    = {{';', 81}};
    nodes[81].isFinal = true;

    // LPAREN
    nodes[82].next    = {{'(', 83}};
    nodes[83].isFinal = true;

    // RPAREN
    nodes[84].next    = {{')', 85}};
    nodes[85].isFinal = true;

    // LBRACE
    nodes[86].next    = {{'{', 87}};
    nodes[87].isFinal = true;

    // RBRACE
    nodes[88].next    = {{'}', 89}};
    nodes[89].isFinal = true;

    // COLON
    nodes[90].next    = {{':', 91}};
    nodes[91].isFinal = true;

    // WS
    nodes[92].next = {
        {' ', 93},
        {'\t', 93},
        {'\n', 93},
        {'\r', 93}};
    nodes[93].next = {
        {' ', 93},
        {'\t', 93},
        {'\n', 93},
        {'\r', 93}};
    nodes[93].isFinal = true;

    // 按照优先级把每一个终止状态和词法单元名对应
    vector<pair<int, string>> final_states = {
        {5, "FUNC"},
        {9, "VAR"},
        {12, "IF"},
        {17, "GOTO"},
        {24, "RETURN"},
        {28, "INT"},
        {33, "BOOL"},
        {35, "ID"},
        {37, "INT_LITERAL"},
        {39, "ADD"},
        {41, "SUB"},
        {43, "MUL"},
        {45, "DIV"},
        {48, "EQ"},
        {51, "NEQ"},
        {53, "LT"},
        {55, "GT"},
        {58, "LE"},
        {61, "GE"},
        {64, "AND"},
        {67, "OR"},
        {69, "NOT"},
        {71, "BITWISE_AND"},
        {73, "BITWISE_OR"},
        {75, "BITWISE_NOT"},
        {77, "ASSIGN"},
        {79, "COMMA"},
        {81, "SEMICOLON"},
        {83, "LPAREN"},
        {85, "RPAREN"},
        {87, "LBRACE"},
        {89, "RBRACE"},
        {91, "COLON"},
        {93, "WS"}};

    // 使用子集构造法生成 DFA 的状态转移表
    // 1. 初始化状态集合
    // 2. 对每个状态集合进行状态转移
    // 3. 如果状态集合中有终止状态，则将其标记为终止状态
    // 4. 如果状态集合中没有终止状态，则将其标记为非终止状态
    // 5. 如果状态集合中没有未访问的状态，则结束
    // 6. 否则，返回第 2 步
    // 7. 输出状态转移表
    // 8. 输出终止状态集合

    unordered_map<DFA_Status, unordered_map<char, DFA_Status>, DFA_StatusHash> DFAtran;

    vector<DFA_Status> DFAset;
    DFA_Status         s0 = {{1, 6, 10, 13, 18, 25, 29, 34, 36, 38, 40, 42, 44, 46, 49, 52, 54, 56, 59, 62, 65, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92}, false};
    DFAset.push_back(s0);

    while (true)
    {
        const auto it = ranges::find_if(DFAset, [](const DFA_Status& s)
                                        { return !s.isVisited; });
        if (it == DFAset.end())
            break;

        // 给 T 加上 visited 标记
        it->isVisited = true;
        // 取出当前状态
        DFA_Status T = *it;

        // 遍历ASCII字符集
        for (char c : ranges::iota_view(0, 128))
        {
            DFA_Status U;
            for (int i : T.indexs)
            {
                if (nodes[i].next.contains(c))
                {
                    U.indexs.insert(nodes[i].next[c]);
                }
            }

            DFAtran[T][c] = U;

            // 如果 U 不在 DATASET 中，则将其添加到 DATASET 中
            if (ranges::find(DFAset, U) == DFAset.end())
                DFAset.push_back(U);
        }
    }


    // 把 DFAset[1] 和 DFAset[0] 交换一下
    swap(DFAset[1], DFAset[0]);

    // 下面是输出每一个 DFA_Status 的子集
    // 同时按照优先级找出 DFA 的终止状态并标记词法单元名称

    // 这个用来记录每一个终止状态对应的 DFA 的状态
    // 用来生成 get_token_type() 函数
    unordered_map<string, vector<int>> DFA_final_states;

    cout << "// 0 -> [] (DEAD)" << endl;
    cout << "// 1 -> [";
    for (int a : DFAset[1].indexs | views::take(DFAset[1].indexs.size() - 1))
    {
        cout << format("{},", a);
    }
    cout << format("{}] (START)", *DFAset[1].indexs.rbegin()) << endl;


    for (size_t i = 2; i < DFAset.size(); ++i)
    {
        cout << format("// {} -> [", i);
        for (int a : DFAset[i].indexs | views::take(DFAset[i].indexs.size() - 1))
        {
            cout << format("{},", a);
        }
        cout << format("{}]", *DFAset[i].indexs.rbegin());

        // 寻找终止状态
        for (auto& [k, v] : final_states)
        {
            if (DFAset[i].indexs.contains(k))
            {
                cout << format(" ({})", v);
                DFA_final_states[v].push_back(i);
                break;
            }
        }
        cout << endl;
    }

    // 生成 get_token_type 函数
    cout << R"(
TokenType Lexer::get_token_type() const
{
    switch (status_)
    {
)";
    for (auto& v : final_states | views::values)
    {
        if (v == "WS")
            continue;

        cout << "\t\t";
        vector<int> status = DFA_final_states[v];
        for (int a : status)
        {
            cout << format("case {} :", a);
        }
        cout << format("return TokenType::{};", v) << endl;
    }
    cout << "\t\t";
    cout << R"(default : return TokenType::ERROR;
    }
}
)" << endl;


    // 将每一个 DFA_Status 映射到 int
    unordered_map<DFA_Status, int, DFA_StatusHash> status_map;
    for (size_t i = 0; i < DFAset.size(); ++i)
    {
        status_map[DFAset[i]] = i;
    }

    // 把 DFAtran 中的 DFA_Status 映射到 int
    map<int, map<char, int>> DFAtran_index;
    for (const auto& [key, value] : DFAtran)
    {
        int index = status_map[key];
        for (const auto& [c, s] : value)
        {
            DFAtran_index[index][c] = status_map[s];
        }
    }

    // 输出 DFAtran_index 的二维数组的形式
    cout << "char DFAtran[54][128] = {" << endl;

    for (int i = 0; i < 54; ++i)
    {
        cout << "{";
        for (int j = 0; j < 127; ++j)
        {
            cout << format("{},", DFAtran_index[i][j]);
        }
        cout << DFAtran_index[i][127];
        cout << "}," << endl;
    }
    cout << "};" << endl;
}