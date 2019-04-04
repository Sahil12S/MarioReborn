#include "StateMachine.h"
#include <iostream>

namespace MarioEngine
{
    StateMachine::StateMachine()
    {

    }

    StateMachine::~StateMachine()
    {
        while ( !m_States.empty() )
        {
            m_States.pop();
        }
        std::clog << "All states destroyed" << std::endl;
    }

    void StateMachine::AddState(MarioEngine::StateRef newState, bool isReplacing)
    {
        m_IsAdding = true;
        m_IsReplacing = isReplacing;

        m_NewState = std::move( newState );
    }

    void StateMachine::ProcessStateChange()
    {
        if ( m_IsRemoving && !m_States.empty() )
        {
            m_States.pop();

            if ( !m_States.empty() )
            {
                std::clog << "Resumed top state" << std::endl;
                m_States.top()->Resume();
            }
            m_IsRemoving = false;
        }

        if ( m_IsAdding )
        {
            if ( !m_States.empty() )
            {
                if (m_IsReplacing)
                {
                    m_States.pop();
                } else
                {
                    std::clog << "Paused top state" << std::endl;
                    m_States.top()->Pause();
                }
            }

            m_States.push( std::move( m_NewState ) );
            m_States.top()->Init();
            m_IsAdding = false;
        }
    }

    void StateMachine::RemoveState()
    {
        m_IsRemoving = true;
    }

    StateRef& StateMachine::GetActiveState()
    {
        return m_States.top();
    }

    // void StateMachine::DeleteMachine()
    // {
    //     ~
    // }
}