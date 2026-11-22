#include "BaseClient.h"

void BaseClient::Startup()
{

}

bool BaseClient::CloseSocket()
{
    return true;
}

bool BaseClient::OpenSocket([[maybe_unused]]int port)
{
    return true;
}

BaseClient::BaseClient(QObject *parent) :
    QObject(parent),
    Name(""),
    is_disconnected(false)
{

}

BaseClient::~BaseClient()
{

}
