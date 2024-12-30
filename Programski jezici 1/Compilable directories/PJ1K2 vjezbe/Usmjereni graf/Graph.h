#pragma once
#include <functional>
#include <set>
#include <queue>
#include <map>
#include <memory>

template <typename T, typename Id = std::string>
class DirectedGraph
{
public:
public:
	class Vertex
	{
	private:
		T value;
		Id id;
		std::set<Vertex*> neighbours;
		friend class DirectedGraph;
	public:
		Vertex(Id id, const T& value) : value(value), id(id)
		{
			static_assert(std::is_copy_constructible<T>::value, "T must be copy constructible");
		}
		Vertex(Id id, T&& value) : value(std::move(value)), id(id)
		{
			static_assert(std::is_move_constructible<T>::value, "T must be move constructible");
		}
		const T& getValue() const { return value; }
		const std::string& getId() const { return id; }
		void traverseBfs(const std::function<void(const T&)>& action) const
		{
			std::set<Id> visited;
			visited.emplace(id);
			std::queue<const Vertex*> toVisit;
			toVisit.push(this);
			while (!toVisit.empty())
			{
				const Vertex* currentVertex = toVisit.front();
				toVisit.pop();
				for (Vertex* neighbour : currentVertex->neighbours)
					if (visited.find(neighbour->id) == visited.end())
					{
						visited.emplace(neighbour->id);
						toVisit.push(neighbour);
					}
				action(currentVertex->value);
			}
		}
	};
private:
	std::map<Id, std::unique_ptr<Vertex>> vertices;
public:
	bool add(const Id& id, const T& value)
	{
		if (vertices.find(id) != vertices.end())
			return false;
		vertices.emplace(id, std::make_unique<Vertex>(id, value));
		return true;
	}
	bool add(const Id& id, T&& value)
	{
		if (vertices.find(id) != vertices.end())
			return false;
		vertices.emplace(id, std::make_unique<Vertex>(id, std::move(value)));
		return true;
	}
	
	void connect(const Id& id1, const Id& id2)
	{
		vertices[id1]->neighbours.emplace(vertices[id2].get());
	}

	// Throws std::out_of_range if id is not found
	const Vertex& getVertex(const Id& id) const
	{
		return *vertices.at(id);
	}

	std::vector<const Vertex*> getVertices() const
	{
		std::vector<const Vertex*> result;
		for (const auto& pair : vertices)
			result.push_back(pair.second.get());
		return result;
	}
};

