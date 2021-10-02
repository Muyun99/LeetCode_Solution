class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> citiesA;
        int size = paths.size();
        for (int i = 0; i < size; ++i)
        {
            citiesA.insert(paths[i][0]);
        }
        for (int i = 0; i < size; ++i)
        {
            if (!citiesA.count(paths[i][1]))
                return paths[i][1];
        }
        return "";
    }
};