class Person:
    def __init__(self, left, right):
        self.left = left
        self.right = right

def main():
    count = int(input())
    a = [Person(*map(int, input().split())) for _ in range(count+1)]

    a[1:] = sorted(a[1:], key=lambda p: p.left * p.right)

    ans = 0
    
    for i in range(1, count+1):
        pre = a[0].left
        for j in range(1, i):
            pre *= a[j].left
        pre = pre // a[i].right
        ans = max(ans, pre)

    print (ans)
    
main()
