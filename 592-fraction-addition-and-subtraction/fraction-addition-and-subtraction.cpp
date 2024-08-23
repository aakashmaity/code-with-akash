class Solution {
public:
    string fractionAddition(string expr) {
        int n = expr.size();

        int nume = 0;
        int deno = 1;

        int i=0;
        while(i<n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if(expr[i] == '+' || expr[i] == '-'){
                i++;
            }

            // build numerator
            while(i<n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            if(isNeg == true){
                currNume *= -1;
            }

            // to skip the '/'
            i++;

            // build denominator
            while(i<n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }


            nume = nume*currDeno + deno*currNume;
            deno = deno *currDeno;
        }

        // gcd(-3,6) -> gives GCD=-3 , to avoid this we will use abs()
        int GCD = abs(__gcd(nume,deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};