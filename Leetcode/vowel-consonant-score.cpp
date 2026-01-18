class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int vowelConsonantScore(string s)
    {
        int n = s.size();
        int vow = 0;
        int cons = 0;
        for (char c : s)
        {
            if (c < 'a' || c > 'z')
                continue;
            if (isVowel(c))
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }

        if (cons > 0)
        {
            return vow / cons;
        }

        return 0;
    }
};