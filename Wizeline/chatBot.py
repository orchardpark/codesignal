def solution(conversations, currentConversation):
    unique_words_conversations = []
    unique_words_current_conversation = set(currentConversation)
    for conversation in conversations:
        unique_words_conversations.append(set(conversation))
    
    max_match = 0
    max_match_index = -1
    
    for idx in range(len(conversations)):
        match = len(unique_words_current_conversation.intersection(unique_words_conversations[idx]))
        if match > max_match:
            max_match = match
            max_match_index = idx
    
    if max_match_index == -1:
        return currentConversation
    
    else:
        selected_conversation = conversations[max_match_index]
        highest_match_index = 0
        for idx, word in enumerate(selected_conversation):
            if word in unique_words_current_conversation:
                highest_match_index = idx
        currentConversation.extend(selected_conversation[highest_match_index+1:])
        return currentConversation
