class Solution
{
public:
    string replaceSpace(string s)
    {
        string news = "";
        int size = s.size();

        for (int i = 0; i < size; ++i)
        {
            if (s[i] == ' ')
                news += "%20";
            else
                news.push_back(s[i]);
        }
        return news;
    }
};
