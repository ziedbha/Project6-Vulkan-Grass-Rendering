#pragma once

#include "Device.h"
#include "SwapChain.h"
#include "Scene.h"
#include "Camera.h"

class Renderer {
public:
	Renderer() = delete;
	Renderer(Device* device, SwapChain* swapChain, Scene* scene, Camera* camera);
	~Renderer();

	void CreateCommandPools();

	void CreateRenderPass();

	// Desc Set Layout
	void CreateCameraDescriptorSetLayout();
	void CreateModelDescriptorSetLayout();
	void CreateTimeDescriptorSetLayout();
	void CreateComputeDescriptorSetLayout();
	void CreateGrassDescriptorSetLayout();

	// Desc Pool
	void CreateDescriptorPool();

	// Desc Set
	void CreateCameraDescriptorSet();
	void CreateModelDescriptorSets();
	void CreateTimeDescriptorSet();
	void CreateComputeDescriptorSets();
	void CreateGrassDescriptorSets();

	void CreateGraphicsPipeline();
	void CreateGrassPipeline();
	void CreateComputePipeline();

	void CreateFrameResources();
	void DestroyFrameResources();
	void RecreateFrameResources();

	void RecordCommandBuffers();
	void RecordComputeCommandBuffer();

	void Frame();

private:
	Device* device;
	VkDevice logicalDevice;
	SwapChain* swapChain;
	Scene* scene;
	Camera* camera;

	VkCommandPool graphicsCommandPool;
	VkCommandPool computeCommandPool;

	VkRenderPass renderPass;

	VkDescriptorSetLayout cameraDescriptorSetLayout;
	VkDescriptorSetLayout modelDescriptorSetLayout;
	VkDescriptorSetLayout timeDescriptorSetLayout;
	VkDescriptorSetLayout computeDescriptorSetLayout;
	VkDescriptorSetLayout grassDescriptorSetLayout;

	VkDescriptorPool descriptorPool;

	VkDescriptorSet cameraDescriptorSet;
	std::vector<VkDescriptorSet> modelDescriptorSets;
	VkDescriptorSet timeDescriptorSet;
	std::vector<VkDescriptorSet> computeDescriptorSets;
	std::vector<VkDescriptorSet> grassDescriptorSets;

	VkPipelineLayout graphicsPipelineLayout;
	VkPipelineLayout grassPipelineLayout;
	VkPipelineLayout computePipelineLayout;

	VkPipeline graphicsPipeline;
	VkPipeline grassPipeline;
	VkPipeline computePipeline;

	std::vector<VkImageView> imageViews;
	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;
	std::vector<VkFramebuffer> framebuffers;

	std::vector<VkCommandBuffer> commandBuffers;
	VkCommandBuffer computeCommandBuffer;
};
