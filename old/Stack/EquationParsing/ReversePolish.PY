class StackA():
    def __init__(self):
        self.data = ['$']

    def isempty(self):
        return not self.data

    def push(self, value):
        self.data.append(value)

    def pop(self):
        if self.isempty():
            raise Exception("Stack is empty")
        else:
            returnVal = self.data[-1]
            self.data = self.data[:-1]
            return returnVal

    def staclTop(self):
        if not self.isempty():
            return self.data[-1]
        else:
            return 5


class CHar():
    def __init__(self, string):
        self.data = string
        self.index = 0

    def show(self):
        return self.data[self.index]

    def nextchar(self):
        self.index += 1


dict = {
    '$': 0,
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
}


def main():
    string = CHar(input())

    stack = StackA()

    output = ''

    def checkval(char):
        if char in dict.keys():
            return dict[char]
        else:
            return 3

    while string.show() != '$':
        while checkval(string.show()) <= checkval(stack.staclTop()):
            output += stack.pop()
        stack.push(string.show())
        string.nextchar()
    while stack.staclTop() != '$':
        output += stack.pop()

    print(output)


if __name__ == "__main__":
    main()
