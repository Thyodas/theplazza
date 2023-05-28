#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <cstdlib>

int main() {
    // Message queue attributes
    mq_attr queueAttributes;
    queueAttributes.mq_flags = 0;
    queueAttributes.mq_maxmsg = 10;    // Maximum number of messages in the queue
    queueAttributes.mq_msgsize = 50;   // Maximum message size
    queueAttributes.mq_curmsgs = 0;

    // Create or open the message queue
    mqd_t mqDescriptor = mq_open("/my_message_queue", O_CREAT | O_RDWR, 0666, &queueAttributes);
    if (mqDescriptor == -1) {
        std::cerr << "Error opening the message queue." << std::endl;
        return 1;
    }

    // Send a message to the queue
    char message[] = "Hello, Message Queue!";
    if (mq_send(mqDescriptor, message, sizeof(message), 0) == -1) {
        std::cerr << "Error sending message to the queue." << std::endl;
        return 1;
    }

    // Receive a message from the queue
    char receivedMessage[50];
    unsigned int priority;
    if (mq_receive(mqDescriptor, receivedMessage, sizeof(receivedMessage), &priority) == -1) {
        std::cerr << "Error receiving message from the queue." << std::endl;
        return 1;
    }

    std::cout << "Received message: " << receivedMessage << std::endl;

    // Close and unlink the message queue
    mq_close(mqDescriptor);
    mq_unlink("/my_message_queue");

    return 0;
}
