#include <iostream>
#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
    std::cout << "GraphEdge Constructor" << std::endl;

    _id = id;
}

GraphEdge::~GraphEdge()
{
    std::cout << "GraphEdge Destructor" << std::endl;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}