//@	{
//@	 "targets":[{"name":"engine.o","type":"object"}]
//@	}

#include "engine.hpp"
#include "angle/init.hpp"
#include <utility>

#include <cstdio>

using namespace Glinde;

namespace
	{
	struct GLFWCreationHints
		{
		explicit constexpr GLFWCreationHints(const Angle::VersionRequest& req):
			 clientAPI(GLFWmm::Session::ClientAPI::OPENGL)
			,clientAPIVersionMajor(req.major)
			,clientAPIVersionMinor(req.minor)
			,clientAPIForwardCompat(req.forward_compatible)
			,clientAPIProfile(GLFWmm::Session::ClientAPIProfile::ANY)
			{
			switch(req.profile)
				{
				case Angle::VersionRequest::Profile::CORE:
					clientAPIProfile=GLFWmm::Session::ClientAPIProfile::CORE;
					break;
				case Angle::VersionRequest::Profile::COMPAT:
					clientAPIProfile=GLFWmm::Session::ClientAPIProfile::COMPAT;
					break;
				case Angle::VersionRequest::Profile::ANY:
				default:
					clientAPIProfile=GLFWmm::Session::ClientAPIProfile::ANY;
					break;
				}
			}

		GLFWmm::Session::ClientAPI clientAPI;
		int clientAPIVersionMajor;
		int clientAPIVersionMinor;
		bool clientAPIForwardCompat;
		GLFWmm::Session::ClientAPIProfile clientAPIProfile;
		static constexpr bool srgb=1;
		};

	static GLFWmm::Session sessionCreate()
		{
		GLFWmm::Session ret;
		ret.creationHints(GLFWCreationHints(Angle::gl_version_requirements()));
		return std::move(ret);
		}
	}

Engine::Engine():m_session(sessionCreate())
	,m_mainwin(0.5f,0.5f,"Glinde",m_cb,m_session)
	{
	m_mainwin.contextCapture();
	auto version=Angle::init();
	fprintf(stderr,"%s %s %s %s\n",version.vendor,version.renderer,version.version,version.glsl_version);
	}

void Engine::run()
	{
	while(!m_mainwin.shouldClose())
		{
		m_session.eventsPoll();
		}
	}
