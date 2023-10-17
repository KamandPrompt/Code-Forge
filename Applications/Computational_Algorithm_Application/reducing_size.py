# HUFFMAN CODING for data message storage using less space
#You can code same in other language but that will be very long hence it is coded in python.

'''
PRINCIPLE
works on the principle of trees it is the real life application
of data structure like tree and priority queue to store large data 
in coded form which consumes less space than original data. 
'''
'''
APPLICATION-
    majorly used for message transfer through server as storage is easy.
    fax machine used this to transfer data.
'''

'''
LOGIC-
    as string takes a lot of space (8bits per char) we reduce this
    size by converting it into code using frequency of characters

    1)first we store frequency in a list in sorted order
    2)then we take first 2 val and start making a tree with these 2 
      as left and right node and sum of these as parent node.
    3)then we make next element and this parent node as child of parent node 
      whose val is sum of these 2.
    4)continue till you iterate over list
    5)put weight of right branch as 1 and left branch as 0.
    6)as you move down the node to charater store the binary code you 
      will pass through 
    7)the code you get for each char is huffman code.
'''

'''
MATHEMATICS-
    on getting the code compare the initial and final memory occupied by
    for initial- (8bits per char)*(length of message)
    after coding-(8bits per char)*(no of unique char)+(1bit * sum of frequency of char)
                    +(len of code for that char * frequency of that char)
    
    calculate the result for any array and you will see the difference in storage of data.
'''
#give input
print("type the string for which you want code for")
string=input()

# Creating tree structure with nodes

class Tree(object):

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self): #setting children of nodes
        return (self.left, self.right)

    def nodes(self):#setting nodes itself
        return (self.left, self.right)

    def __str__(self):
        return (self.left, self.right)

# Calculating frequency of each character and storing it in dictionary
frequency = {}
for character in string:
    if character in frequency:
        frequency[character] += 1
    else:
        frequency[character] = 1

frequency = sorted(frequency.items(), key=lambda x: x[1], reverse=True) #sorting the map/dictionary

nodes = frequency #creating nodes dictionary/map as copy of original frequency dictionary

while len(nodes) > 1: #setting nodes according to child
    (key1, c1) = nodes[-1]
    (key2, c2) = nodes[-2]
    nodes = nodes[:-2]
    node = Tree(key1, key2)
    nodes.append((node, c1 + c2))

    nodes = sorted(nodes, key=lambda x: x[1], reverse=True)#sorting the nodes after creating them

# Main function implementing huffman coding
def huffman_tree(node, left=True, code=''):
    if type(node) is str:
        return {node: code}
    (l, r) = node.children()
    dictionary = dict()
    dictionary.update(huffman_tree(l, True, code + '0'))#updating the codes values according to position in tree
    dictionary.update(huffman_tree(r, False, code + '1'))#updating the codes values according to position in tree
    return dictionary

huffmanCode = huffman_tree(nodes[0][0])

print('huffman code for your message is')
print('(Char,Huffman code) ')
print('  |    |')
for (char, frequency) in frequency:
    print((char, huffmanCode[char]))


