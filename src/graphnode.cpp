#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
//    std::cout << "GraphNode Constructor" << std::endl;
//
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

//    std::cout << "GraphNode Destructor" << std::endl;
//
//    delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge* edge)
{
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
//{
//    std::cout << "Moving ChatBot Pointer to new node" << std::endl;
//
//    _chatBot = *chatbot;
//    _chatBot->SetCurrentNode(this);
//}

void GraphNode::MoveChatbotHere(std::shared_ptr<ChatBot> chatbot)
{
//    std::cout << "Moving ChatBot SHARED Pointer to new node " << chatbot.get() << std::endl;

    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

//void GraphNode::MoveChatbotHere(ChatBot&& chatbot)
//{
//    std::cout << "Moving ChatBot rvalue Reference to new node" << &chatbot << std::endl;
//
////    _chatBot = &chatbot;
//     _chatBot = new ChatBot(chatbot);
//    _chatBot->SetCurrentNode(this);
//}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}