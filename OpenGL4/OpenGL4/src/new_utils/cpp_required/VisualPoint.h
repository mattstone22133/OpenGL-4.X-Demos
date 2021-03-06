#pragma once
#pragma once
#include <optional>
#include "../header_only/Transform.h"
#include "../header_only/share_ptr_typedefs.h"
#include "../header_only/Event.h"

//forward declarations
namespace ho
{
	struct Shader;
	struct LineRenderer;
}
namespace StaticMesh
{
	class Model;
}

namespace nho
{
	/** This is a quick copy-paste modification of visual vector, if anything appears strange look at that class for reference. */
	class VisualPoint : public Entity
	{
	public:
		VisualPoint();
		~VisualPoint();

		/** Converting to entity so move/copy semantics cache probably be disregarded*/
		VisualPoint(const VisualPoint& copy);
		VisualPoint& operator=(const VisualPoint& copy);
		VisualPoint(VisualPoint&& move);
		VisualPoint& operator=(VisualPoint&& move);
	public:
		void render(const glm::mat4& projection_view, std::optional<glm::vec3> cameraPos) const;
		void setPosition(glm::vec3 newStart);
		void setUserScale(glm::vec3 newScale);

		/** Additional scaling is applied, user scale is only a portion of that scaling.*/
		glm::vec3 getUserScale() { return pod.scale; }
		glm::vec3 getPosition() { return pod.position; }
		ho::Event<const VisualPoint&> eventValuesUpdated;
	private:
		void updateCache();
	public:
		glm::vec3 color{ 1.f };
		struct POD
		{
			glm::vec3 position{ 0.f };
			glm::vec3 scale{ 1.f };
			glm::mat4 cachedXform{ 1.f };
		};
	private:
		POD pod;
		virtual void onValuesUpdated(const struct POD& values) {};
	private:
		static int numInstances;
		static sp<StaticMesh::Model> pointMesh;
		static sp<ho::Shader> pointShader;
	};

}