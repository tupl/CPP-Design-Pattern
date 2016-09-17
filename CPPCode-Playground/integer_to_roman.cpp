// idea like get the sub unit
// M CM D CD C CX L LX X IX V IV I
class Solution {
public:
    string intToRoman(int num) {
        string roman[13] = {"M", "CM", "D", "CD", "C",
            "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int vals[13] = {1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1};
        string res;
        for(int i = 0; i < 13; ++i) {
            if (num >= vals[i]) {
                int rep = num / vals[i];
                num %= vals[i];
                for(int k = 0; k < rep; ++k) {
                   res.append(roman[i]); 
                }
            }
        }
        return res;
    }
};