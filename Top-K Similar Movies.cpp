/*
    You are given a list of movies with ratings associated with them  and pairs of movies which are similar.
    Given a movie X and a number K , you need to find K similar movies which are highest rated.
    
    Examples:
    
    Movies : [ {"A", 9}, {B,6}, {C,7}, {D,8}, {E,5} ]
    List of similar movies : [ {A, C}, {C, E}, {B,D}]
    Arguments: Movie A, 1
    Answer: {“C”}
*/

priority_queue<pair<int, string>, 
               vector<pair<int, string>>,
               greater<pair<int, string>>> similarKMovies;

string original = “”;

void dfs(unordered_map<string, int>& movies,
         unordered_map<string, vector<string>>& graph, string& argM,
         string& argsParent) {

    if (similarKMovies.top().first > movies[argM] &&
        argM != original) { // klogk
        similarKmovies.pop();
        similarKMovies.push({movies[argM], argM});
    }

    for (auto nei : graph[argM]) { // O(n)
        if (nei == argsParent)
            continue;
        dfs(movies, graph, nei, argM);
    }
}

vector<string> getKSimilarMovies(unordered_map<string, int>& movies,
                                 vector<pair<string, string>>& similar,
                                 String& argM, int k) {
    original = argM;
    unordered_map<string, vector<string>> graph;
  
    for (auto same : similar) { // O(edgesCount)
        graph[same[0]].push_back(same[1]);
        graph[same[1]].push_back(same[0]);
    }

    dfs(movies, graph, argM, “”); // O(klogk + n), O(k)

    if (similarMovies.empty())
        return vector<string>();

    vector<string> res;
    while (!similarMovies.empty()) {
        O(k)
        string s = similarMovies.top();
        similarMovies.pop();
        res.push_back(s);
    }

    return res;
}

// Time: O(klogk + n)
// Space: O(k)


