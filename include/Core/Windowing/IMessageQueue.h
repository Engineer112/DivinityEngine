//
// Created by Hosea on 9/25/2025.
//

#pragma once


namespace Core::Windowing {
    class IMessageQueue {
    public:
        IMessageQueue();

        virtual ~IMessageQueue() = default;

        virtual bool Poll() = 0;
        virtual bool Peek() = 0;
        virtual bool Dispatch() = 0;


        virtual bool Push(/* TODO: -abstract message, -data */) = 0;
    };
}