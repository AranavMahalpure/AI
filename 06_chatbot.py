travel_knowledge_base = {

    "what is your name?" : [
        "I'm the Travel Advisor bot! \n Happy to help you with your travel enquiries!"
    ],

    "hello": [
        "Hello! \n I'm the Travel Advisor bot! \n Happy to help you with your travel enquiries!"
    ],

    "what are the best beaches in thailand?": [
        "Phuket",
        "Koh Samui",
        "Krabi",
        "Pattaya"
    ],

    "which are the best hotels in paris?" : [
        "Le Bristol Paris",
        "Four Seasons Hotel George V",
        "Shangri-La Hotel",
        "Hotel Plaza Athénée"
    ],

    "what are the top tourist attractions in rome?" : [
        "Colosseum",
        "Vatican City",
        "Roman Forum",
        "Pantheon"
    ],

    "When do the flights to new york start?": [
        "Flights to New York generally start around 6 am",
    ],

}
import streamlit as st

st.header("Travel Advisor Chatbot")

def respond(input: str):
    if (input in travel_knowledge_base):
        print(input)
        values = travel_knowledge_base[input]
        for value in values:
            st.write(value)
    else:
        print(input)
        key = input
        st.write("Question is not present in the knowledge base!\nCould you please enter the appropriate answer for the question below-")
        answer = st.text_input("Answer")
        add = st.button("Add answer")
        if (add):
            travel_knowledge_base[key] = [answer]

if __name__ == "__main__":
    input = st.text_input("Enter a question here-")
    input = input.lower()
    col1, col2 = st.columns([1,0.1])
    with col1:
        ask = st.button("Ask")
    with col2:
        quit = st.button("Quit")
    if (ask):
        respond(input)
    if (quit):
        st.write("Thank you for using the Chatbot")