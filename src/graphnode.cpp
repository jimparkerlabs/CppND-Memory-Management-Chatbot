#include <iostream>
#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"

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

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot&& chatbot)
{
//    std::cout << "Moving ChatBot rvalue Reference to new node" << &chatbot << std::endl;

    _chatBot = ChatBot(std::move(chatbot));  // move constructor; move assignment operator

    // moved chatbot, so need to update associated chatlogic to point to new one
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);

    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
//    _chatBot = nullptr; // invalidate pointer at source
//    _chatBot = ChatBot();  // I just moved this, so I should re-set the source variable
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