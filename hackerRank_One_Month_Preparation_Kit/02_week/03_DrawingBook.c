int pageCount(int n, int p) {
    int fromFront, fromBack;
    
    fromFront = p / 2;
    
    if (n % 2 == 0) {
        fromBack = (n - p + 1) / 2;
    } else {
        fromBack = (n - p) / 2;
    }
    
    return (fromFront < fromBack) ? fromFront : fromBack;
}