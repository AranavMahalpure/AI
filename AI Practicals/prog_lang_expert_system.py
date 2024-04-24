fitness_knowledge_base = {
    "Build Muscle": [
        "Barbell Squats",
        "Deadlifts",
        "Bench Press",
        "Pull-ups",
        "Push-ups",
        "Dips",
        "Lunges",
    ],
    "Lose Weight": [
        "Running",
        "Cycling",
        "Swimming",
        "Jumping Rope",
        "High-Intensity Interval Training (HIIT)",
        "Bodyweight Exercises",
        "Strength Training",
    ],
    "Improve Flexibility": [
        "Yoga",
        "Pilates",
        "Stretching",
        "Tai Chi",
        "Dance",
        "Martial Arts",
    ],
}
import streamlit as st

st.header("Fitness Expert System")

def respond(input: str):
    goal = input
    if goal:
        if goal in fitness_knowledge_base.keys():
            st.write(f"Exercises for {goal}:")
            for exercise in fitness_knowledge_base[goal]:
                st.write("- ", exercise)
        else:
            st.write("Goal is not present in the knowledge base!")
            st.write("Could you please enter the appropriate goal below-")
            goal = st.text_input("Goal")
            add = st.button("Add Goal")
            if add:
                for key in fitness_knowledge_base.keys():
                    if goal == key:
                        fitness_knowledge_base[key].append(goal)

if __name__ == "__main__":
    goal = st.text_input(
        'Which fitness goal would you like to achieve?',
        )

    col1, col2 = st.columns([1, 0.1])
    with col1:
        ask = st.button("Ask")
    with col2:
        quit = st.button("Quit")
    if ask:
        respond(goal)
    if quit:
        st.write("Thank youfor using the Fitness Expert System!")