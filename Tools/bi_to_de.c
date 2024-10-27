int bi_to_de(const char *bi) {
    int de = 0;
    int length = strlen(bi);
    for (int i = 0; i < length; i++) {
        if (bi[length - i - 1] == '1') { //-1！！！因为结尾是\0
            de += (1 << i); //注意加括号
        }
    }
    return de;
}