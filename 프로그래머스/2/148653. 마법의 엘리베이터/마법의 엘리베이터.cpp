int solution(int storey) {
    int answer = 0;
    
    while (storey > 0)
    {
        int digit=storey%10;//1의자리
        int tendigit=(storey/10)%10;//10의자리
        if (digit>5)
        {
            answer+=(10-digit);
            storey+=10;
        }
        else if (digit<5)
        {
            answer+=digit;
        }
        else
        {
            answer+=5;
            if (tendigit>=5)
            {
                storey+=10;
            }
        }
        storey/=10;
    }
    return answer;
}