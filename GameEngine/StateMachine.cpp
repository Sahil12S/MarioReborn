#include "StateMachine.h"
#include "DEFINITIONS.h"

namespace SSEngine
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
        Debug( "All states destroyed" )
    }

    void StateMachine::AddState(SSEngine::StateRef newState, bool isReplacing)
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
                Debug( "Resumed top state" )
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
                    Debug( "Paused top state" )
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