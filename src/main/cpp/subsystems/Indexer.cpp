#include "subsystems/Indexer.hpp"
#include <frc2/command/CommandPtr.h>

Indexer::Indexer() : indexer(6)
{
}
void Indexer::RunIndexer()
{
    indexer.Set(1.0);
}
void Indexer::StopIndexer()
{
    indexer.Set(0.0);
}
frc2::CommandPtr&& Indexer::GetIndexCommand()
{
    return this->Run([=]()
    {
        this->RunIndexer();
    });
}
frc2::CommandPtr&& Indexer::GetDefaultCommand()
{
    return this->Run([=]()
    {
        this->StopIndexer();
    });
}