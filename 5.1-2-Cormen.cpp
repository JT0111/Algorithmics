//Exercise 5.1-2 from "Introduction to Algorithms"
//function returning random number between a and b
//calls only random(0, 1)
//doesn't actually have any use apart of practice
int random(int a, int b){
    int c = b-a, length = 0, randomBinaryNumber=0;
    //finding the length of binary representation of b-a
    while(c>=1){
        c/=2;
        length++;
        randomBinaryNumber*=2;
        randomBinaryNumber+=random(0,1);
    }
    //adding the random binary number to a
    c+=a;
    //unlikely case that I didn't think through
    //it is unlikely but yet I'll improve this part of the solution some other day
    if(c>b){
        return (random(a, b));
    }
return c;
}
