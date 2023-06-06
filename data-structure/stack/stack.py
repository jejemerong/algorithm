from sys import maxsize

def createStack():
    stack = []
    return stack

def isEmpty(stack):
    return len(stack)

def push(stack, item):
    stack.append(item) # append 함수 이용

def pop(stack):
    if(isEmpty(stack)):
        return str(-maxsize -1) # stack underflow 안나게
    return stack.pop

def peek(stack):
    if (isEmpty(stack)):
        return str(-maxsize -1)
    return stack[len(stack) - 1]

stack = createStack()
push(stack, 10)
push(stack, 20)
push(stack, 30)

print(stack) # 최하단 원소부터 출력
print(stack[::-1]) # 최상단 원소부터 출력