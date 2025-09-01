int pageCount(int n, int p) {
    int turnsFromStart = 0;
    int turnsFromEnd = 0;
    
    turnsFromStart = p / 2;
    
    if (n % 2 == 0) {
        turnsFromEnd = (n - p) / 2;
    } else {
        turnsFromEnd = (n - p) / 2;
    }
    
    if (turnsFromStart <= turnsFromEnd) {
        return turnsFromStart;
    } else {
        return turnsFromEnd;
    }
}
