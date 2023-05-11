 //Header Guards to prevent header files from being included multiple times
// #ifndef HUFFMAN_HPP
// #define HUFFMAN_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

//Defining Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <Node*> arr;   //creating a vector of type Node

        fstream inFile, outFile;

        string inFileName, outFileName;
        
        Node *root;
        
        class Compare{
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->freq > r->freq;
                }
        };

       priority_queue <Node*, vector<Node*>, Compare> minHeap;

        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void createArr();

        //Traversing the constructed tree to generate huffman codes of each present character
        void traverse(Node*, string);

        //Function to convert binary string to its equivalent decimal value
        int binToDec(string);

        //Function to convert a decimal number to its equivalent binary string
        string decToBin(int);

        //Reconstructing the Huffman tree while Decoding the file
        void buildTree(char, string&);

        //Creating Min Heap of Nodes by frequency of characters in the input file
        void createMinHeap();

        //Constructing the Huffman tree
        void createTree();

        //Generating Huffman codes
        void createCodes();

        //Saving Huffman Encoded File
        void saveEncodedFile();

        //Saving Decoded File to obtain the original File
        void saveDecodedFile();

        //Reading the file to reconstruct the Huffman tree
        void getTree();

    public:
        //Constructor
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;

        // std::ifstream file(inFileName);
        // if (file.is_open()) {
        //     file.seekg(0, std::ios::end); // Move file pointer to end of file
        //     int size = file.tellg(); // Get current position of file pointer
        //     std::cout << "File size: " << size << " bytes" << std::endl;
        //     file.close();
        // }
        //  else {
        // std::cout << "Error opening file" << std::endl;
        // }

            createArr();
        }

        //Compressing input file
        void compress();
        //Decrompressing input file
        void decompress();
};
// #endif