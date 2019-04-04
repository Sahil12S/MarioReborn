#pragma once

#include <stack>
#include <memory>
#include "State.h"

namespace MarioEngine
{
    /*
     * Pointer reference to our game state
     */
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        StateMachine();
        ~StateMachine();

        /*
         * Add a new state to stack
         * by default, remove existing one.
         * We need to preserve existing state when we go to Pause state
         */
        void AddState( StateRef newState, bool isReplacing = true );

        /*
         * Remove state from stack
         */
        void RemoveState();

        /*
         * Processes the state change (weather add new or update existing)
         */
        void ProcessStateChange();

        // void DeleteMachine();

        /*
         * Return top level state which we have to run
         */
        StateRef& GetActiveState();

    private:
        std::stack<StateRef> m_States;

        StateRef m_NewState;

        /*
         * Check for action with state
         */
        bool m_IsAdding;
        bool m_IsRemoving;
        bool m_IsReplacing;
    };
}