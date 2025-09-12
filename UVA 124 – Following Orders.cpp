/*
Order is an important concept in mathematics and in computer science. For example, 
Zorn’s Lemma states: “a partially ordered set in which every chain has an upper bound 
contains a maximal element.” Order is also important in reasoning about the fix-point semantics of programs. 
This problem involves neither Zorn’s Lemma nor fix-point semantics, but does involve order. 
Given a list of variable constraints of the form x < y, you are to write a program that prints all orderings 
of the variables that are consistent with the constraints. 
For example, given the constraints x < y and x < z there are two orderings of the variables x, y, and z that 
are consistent with these constraints: xyz and xzy. 
Input 
The input consists of a sequence of constraint specifications. A specification consists of two lines: 
a list of variables on one line followed by a list of constraints on the next line. 
A constraint is given by a pair of variables, where ‘x y’ indicates that x < y. 
All variables are single character, lower-case letters. There will be at least two variables, 
and no more than 20 variables in a specification. There will be at least one constraint, 
and no more than 50 constraints in a specification. There will be at least one, 
and no more than 300 orderings consistent with the constraints in a specification. Input is terminated by end-of-file. 
Output 
For each constraint specification, all orderings consistent with the constraints should be printed. 
Orderings are printed in lexicographical (alphabetical) order, one per line. Output for different constraint specifications 
is separated by a blank line. 
Sample Input: 
a b f g 
a b b f 

Sample Output: 
abfg 
abgf 
agbf 
gabf 

Graph:  g   a->b->f
a b f g
a b g f
a g b f
g a b f
*/
vector<string> res;
void topoSort(unordered_map<char, vector<char>>& graph,
              unordered_map<char, int>& inDegree, string current,
              set<char> zero) {
    if (current.size() == inDegree.size()) {
        res.push_back(current);
        return;
    }
    for (auto it = zero.begin(); it != zero.end(); ++it) {
        char node = *it;
        string nextCurrent = current + node;
        auto nextZero = zero;
        nextZero.erase(node);
        auto nextInDegree = inDegree;
        for (char nei : graph[node]) {
            nextInDegree[nei]--;
            if (nextInDegree[nei] == 0) {
                nextZero.insert(nei);
            }
        }

        topoSort(graph, nextInDegree, nextCurrent, nextZero);
    }
}

vector<string> generateAllOrderings(vector<char>& variables,
                                    vector<char>& constraints) {
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> inDegree;

    for (char c : variables) {
        graph[c];
        inDegree[c] = 0;
    }

    for (int i = 0; i < constraints.size(); i += 2) {
        char src = constraints[i];
        char dst = constraints[i + 1];
        graph[src].push_back(dst);
        inDegree[dst]++;
    }

    set<char> zero;
    for (char c : variables)
        if (inDegree[c] == 0)
            zero.insert(c);

    string current = "";
    res.clear();
    topoSort(graph, inDegree, current, zero);
    return res;
}
